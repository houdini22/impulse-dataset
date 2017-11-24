# impulse-ml

## Description

This library can be used to manage datasets used in other impulse-ml
libraries.

It supports:

###### Importing:
 - Loading data from CSV

###### Column transformations:
 - Category transformation

Given string data stacked in examples i.e.: {"Cat1", "Cat2", "Cat3", "Cat1"}
are transformed into binary categories: {<0|1>, <0|1>, <0,1>}
(3 unique categories)

 - CategoryId transformation

Given string data stacked in examples i.e.: {"Cat1", "Cat2", "Cat3", "Cat1"}
are transformed into unique numbers: 0, 1, 2, 3

 - MinMaxScaling [https://en.wikipedia.org/wiki/Feature_scaling#Rescaling]
 - ZScoresScaling [https://en.wikipedia.org/wiki/Feature_scaling#Standardization]
 - MissingData - it can create mean values for missing data in example columns

###### Dataset transformations

 - slicing: for dividing input set and output set
 - splitting: i.e. for train set, dev set and test set

### TODO:
 - use OpenMP
 - implement export to file
 - fix demo paths
