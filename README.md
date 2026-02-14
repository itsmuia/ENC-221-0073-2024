import pandas as pd
import geopandas as gpd
from shapely.geometry import Point
import random

# --- 1. GENERATE MOCK DATA ---
print("Generating survey data...")
center_lat, center_lon = 40.7128, -74.0060  # NYC Area
rows = []
for i in range(1, 16):
    rows.append({
        'id': f'PT_{i}',
        'lat': center_lat + random.uniform(-0.005, 0.005),
        'lon': center_lon + random.uniform(-0.005, 0.005),
        'type': random.choice(['Manhole', 'Post', 'Tree'])
    })

df = pd.DataFrame(rows)
df.to_csv('raw_survey.csv', index=False)
print("Created 'raw_survey.csv'")

# --- 2. IMPORT AND CONVERT TO GEOMETRY ---
# Load the CSV we just made
df_raw = pd.read_csv('raw_survey.csv')

# Create 'Point' objects (Longitude first, then Latitude)
geometry = [Point(xy) for xy in zip(df_raw['lon'], df_raw['lat'])]

# Create a GeoDataFrame
# EPSG:4326 = Standard WGS84 (Global GPS coordinates)
gdf = gpd.GeoDataFrame(df_raw, geometry=geometry, crs="EPSG:4326")

# --- 3. TRANSFORM COORDINATES ---
# Transform to EPSG:3857 (Web Mercator - used by Google/OpenStreetMap)
# This changes coordinates from Degrees to Meters
gdf_transformed = gdf.to_crs("EPSG:3857")
print("Transformed coordinates from Degrees to Meters.")

# --- 4. EXPORT TO GIS FORMATS ---
# Export to GeoPackage (Single file, modern GIS standard)
gdf_transformed.to_file("final_survey.gpkg", layer='points', driver="GPKG")

# Export to GeoJSON (Great for web maps)
gdf_transformed.to_file("final_survey.json", driver='GeoJSON')

print("\n--- DONE ---")
print("Files generated:")
print("1. raw_survey.csv (Raw Data)")
print("2. final_survey.gpkg (GIS Geopackage)")
print("3. final_survey.json (Web-friendly GIS)")
