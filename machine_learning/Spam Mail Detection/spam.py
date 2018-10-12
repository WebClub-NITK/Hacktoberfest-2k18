# -*- coding: utf-8 -*-
"""
Created on Sun Mar  4 10:08:36 2018

@author: yogendra
"""

import pandas as pd
import numpy as np
import matplotlib as plt

#imorting the dataset
dataset=pd.read_csv('spam.csv')

#cleannig the dataset
import re
import nltk
nltk.download('stopwords')
from nltk.corpus import stopwords
from nltk.stem.porter import PorterStemmer
corpus=[]
for i in range(0,5572):
    test=re.sub('[^a-zA-Z]',' ',dataset['v2'][i])
    test=test.lower()
    test=test.split()
    ps=PorterStemmer()
    test=[ps.stem(word) for word in test if not word in set(stopwords.words('english'))]
    test=' '.join(test)
    corpus.append(test)
 

#creating the bag of words
from sklearn.feature_extraction.text import CountVectorizer
cv = CountVectorizer(1500) 
X = cv.fit_transform(corpus).toarray()  
y=dataset.iloc[:,0].values


# Splitting the dataset into the Training set and Test set
from sklearn.cross_validation import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.20, random_state = 0)


# Fitting Naive Bayes to the Training set
from sklearn.naive_bayes import BernoulliNB
classifier = BernoulliNB()
classifier.fit(X_train, y_train)


#predicting the Test result output
y_pred=classifier.predict(X_test)


#Generating the confusion matrix
from sklearn.metrics import confusion_matrix
cn=confusion_matrix(y_test,y_pred)

#checking the accuracy of model
from sklearn.metrics import accuracy_score
te=accuracy_score(y_test,y_pred)

#logistic regression
from sklearn.linear_model import LogisticRegression
classifier1=LogisticRegression(random_state=0)
classifier1.fit(X_train,y_train)

#Testing the result with test dataset
y_pred1=classifier1.predict(X_test)

from sklearn.metrics import accuracy_score
te1=accuracy_score(y_test,y_pred1)

from sklearn.metrics import confusion_matrix
cn1=confusion_matrix(y_test,y_pred1)


#K-Nearest Neighbours
from sklearn.neighbors import KNeighborsClassifier
kn=KNeighborsClassifier(n_neighbors=5,metric='minkowski', p = 2)
kn.fit(X_train,y_train)

#predicting the Test set result
y_pred2=kn.predict(X_test)

cn2=confusion_matrix(y_test,y_pred2)

te2=accuracy_score(y_test,y_pred2)







