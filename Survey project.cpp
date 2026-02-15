#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

/* ===================== LOGGER ===================== */
class Logger {
public:
    static void log(const string& message) {
        cout << "[LOG] " << message << endl;
    }
};

/* ===================== GEOMETRY ===================== */
class Geometry {
public:
    virtual string getType() const = 0;
    virtual ~Geometry() {}
};

class Point : public Geometry {
public:
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    string getType() const override {
        return "Point";
    }
};

class Line : public Geometry {
public:
    vector<Point> points;

    string getType() const override {
        return "Line";
    }
};

class Polygon : public Geometry {
public:
    vector<Point> vertices;

    string getType() const override {
        return "Polygon";
    }
};

/* ===================== CSV READER ===================== */
class CSVReader {
public:
    static vector<Point> readPoints(const string& filename) {
        vector<Point> points;
        ifstream file(filename);

        if (!file.is_open()) {
            Logger::log("Error opening file!");
            return points;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            double x, y;
            char comma;

            if (ss >> x >> comma >> y) {
                points.emplace_back(x, y);
            }
        }

        file.close();
        Logger::log("CSV data imported successfully");
        return points;
    }
};

/* ===================== TRANSFORMER ===================== */
class Transformer {
public:
    static void translate(Point& p, double dx, double dy) {
        p.x += dx;
        p.y += dy;
    }
};

/* ===================== EXPORT INTERFACE ===================== */
class Exporter {
public:
    virtual void exportData(const vector<Point>& points,
                            const string& filename) = 0;
    virtual ~Exporter() {}
};

/* ===================== GEOJSON EXPORTER ===================== */
class GeoJSONExporter : public Exporter {
public:
    void exportData(const vector<Point>& points,
                    const string& filename) override {

        ofstream file(filename);
        if (!file.is_open()) {
            Logger::log("Error creating GeoJSON file!");
            return;
        }

        file << "{\n";
        file << "  \"type\": \"FeatureCollection\",\n";
        file << "  \"features\": [\n";

        for (size_t i = 0; i < points.size(); i++) {
            file << "    {\n";
            file << "      \"type\": \"Feature\",\n";
            file << "      \"geometry\": {\n";
            file << "        \"type\": \"Point\",\n";
            file << "        \"coordinates\": ["
                 << points[i].x << ", "
                 << points[i].y << "]\n";
            file << "      }\n";
            file << "    }";

            if (i < points.size() - 1)
                file << ",";

            file << "\n";
        }

        file << "  ]\n";
        file << "}\n";

        file.close();
        Logger::log("GeoJSON export completed");
    }
};

/* ===================== CSV EXPORTER ===================== */
class CSVExporter : public Exporter {
public:
    void exportData(const vector<Point>& points,
                    const string& filename) override {

        ofstream file(filename);
        if (!file.is_open()) {
            Logger::log("Error creating CSV file!");
            return;
        }

        for (const auto& p : points) {
            file << p.x << "," << p.y << endl;
        }

        file.close();
        Logger::log("CSV export completed");
    }
};

/* ===================== MAIN PROGRAM ===================== */
int main() {
    Logger::log("Starting Survey Data Integration Tool");

    // Step 1: Read survey CSV data
    vector<Point> points = CSVReader::readPoints("survey_points.csv");

    // Step 2: Coordinate transformation (example shift)
    for (auto& p : points) {
        Transformer::translate(p, 10.0, 10.0);
    }

    // Step 3: Export to GeoJSON
    Exporter* geoExporter = new GeoJSONExporter();
    geoExporter->exportData(points, "output.geojson");
    delete geoExporter;

    // Step 4: Export to CSV
    Exporter* csvExporter = new CSVExporter();
    csvExporter->exportData(points, "output.csv");
    delete csvExporter;

    Logger::log("Process completed successfully");
    return 0;
}
