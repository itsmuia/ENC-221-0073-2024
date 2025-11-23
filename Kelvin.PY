class Neighbor:
    def __init__(self, name, age, height, traits, hobby, education):
        self.name = name
        self.age = age
        self.height = height
        self.traits = traits
        self.hobby = hobby
        self.education = education

    def describe(self):
        print(f"--- Neighbour's Details: {self.name} ---")
        print(f"Name: {self.name}")
        print(f"Age: {self.age} years old")
        print(f"Height: {self.height})
        print(f"Personality: He is{self.traits}.")
        print(f"Hobby: His hobby is {self.hobby}.")
        print(f"Educational Level: He has a {self.education} in finance")
        print("-" * (len(self.name) + 26))
my_neighbor = Neighbor(
       name="Joseph",
       age=21,
       height="6'1",
       personality="hardworking,jovial",
       hobby="swimming",
       education="Diploma"
)
my_neighbor.describe()