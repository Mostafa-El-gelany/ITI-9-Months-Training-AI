import pandas as pd
import numpy as np
class TransactionCleaner:
    def __init__(self):
        self.data = None
    def clean_data(self, data):
        data=data[data.isFraud==0].copy()
        data.drop(['isFlaggedFraud','isFraud'],axis=1,inplace=True)
        data.drop_duplicates(inplace=True)
        return data    