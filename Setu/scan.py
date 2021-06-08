import json
import sqlite3

with open('class_names_6000.json', 'r') as f:
    class_names = json.load(f)

db = sqlite3.connect('Setu.db')

