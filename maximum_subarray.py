#---------------------------------------------------
# Student Name : Sumesh Nellemakkal Balan
# UTA ID : 1001119408
# Extra credit assignment
# Problem : maximum sum of all subarrays
# Complexity O(n) - Linear
#---------------------------------------------------

import sys

#test case 1 - all positive
#a = [1, 2, 3, 4, 5, 6, 7]
#test case 2 - all negative, decreasing order
a = [-1, -2, -3, -4]
#test case 3 - all negative, increasing order
#a = [-4, -3, -2, -1]
#test case 4 - all negative, in random order
#a = [-7, -5, -100, -1, -63]
#test case 5 - positive and negative mix - this input is given by Dr.Cai
#a = [1, -2, 3, 10, -4, 7, 2, -5]
#test case 6 - special case - negative number followed by a larger positive number
#a = [18,-5,6]

# aux array will be used for memoization, also it will be used to track trace backs
# aux will contain tuples (val, 1 or 0) - val indicates the current maximum value
# and the 1 or 0 indicates whether this value is a continuation from previous value
# 1 - indicates that the current value is a continuation of the previous value
# 0 - indicates that the current value is not calculated from previous value
aux = []

def maximum_subarray(a):
    for idx, val in enumerate(a):
        if(idx == 0):
            aux.append((val,0))
            continue
        #case 1
        if( aux[idx-1][0] <= 0):
            aux.append((val,0))
            continue
        #case 2
        if( aux[idx - 1][0] + val >= aux[idx-1]):
            aux.append((aux[idx - 1][0] + val, 1))
            continue
        #case 3
        if(aux[idx -1][0] + val > 0):
            aux.append((aux[idx - 1][0] + val, 1))
            continue
        #case 4
        if(aux[idx - 1][0] + val <= 0):
            aux.append((val, 0))
            continue


def max_sum():
    #find out the maximum value in aux array and its index
    max = -sys.maxint - 1
    max_index = 0
    for idx, val in enumerate(aux):
        if val > max:
            max = val
            max_index = idx

    return max, max_index


def trace_back():
    trace = []
    maxval, index = max_sum();
    for i in xrange(index, -1, -1):
        trace.append(a[i])
        if aux[i][1] == 0:
            break
    #return reversed trace back array
    return trace[::-1]


maximum_subarray(a)
max, max_index = max_sum()
print 'maximum sum of all subarrays:', max[0]
print 'trace back of the solution:',trace_back()