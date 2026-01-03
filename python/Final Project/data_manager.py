import pandas as pd
import numpy as np
class DataManager:
    def __init__(self):
        self.data = None
    def load_data(self):
        self.data = pd.read_csv("D:\ITI\9 Months Training AI\python\Final Project\PS_20174392719_1491204439457_log.csv")
        #shuffle data and take a sample of 100000 rows for performance
        #self.data = self.data.sample(frac=1, random_state=42).reset_index(drop=True).head(100000)
        return self.data
