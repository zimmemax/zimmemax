from dictionaries import Dict, OrderedDict, FrozenDict, FrozenOrderedDict, ReadonlyDictProxy
import random
import string
import sys
import heapq


def dijsktra(graph,start,finish):
    #gives infinite value for an unvisited node (standard algorithm procedure)
    unvisitedNodeValue = sys.maxsize
    vistedNodes = []
    #create a dictionary to store the weight information on the node
    nodeData = {}
    nodeData['A'] = {'weight':unvisitedNodeValue,'pred':[]}
    nodeData['B'] = {'weight':unvisitedNodeValue,'pred':[]}
    nodeData['C'] = {'weight':unvisitedNodeValue,'pred':[]}
    nodeData['D'] = {'weight':unvisitedNodeValue,'pred':[]}
    nodeData['E'] = {'weight':unvisitedNodeValue,'pred':[]}
    nodeData['F'] = {'weight':unvisitedNodeValue,'pred':[]}
    nodeData['G'] = {'weight':unvisitedNodeValue,'pred':[]}
    #establish the starting node to the value of zero
    nodeData[start] = {'weight':0}
    temp = start
    minHeap = []
    #create a loop for the 6 steps required to fully traverse through the graph (n-1) n being the number of vertices
    for i in range (6):
        if temp not in vistedNodes:
            vistedNodes.append(temp)
        for x in graph[temp]:
            if x not in vistedNodes:
                cost = nodeData[temp]['weight'] + graph[temp][x]
                #determine if total weight of pred is less than current weight
                if cost < nodeData[x]['weight']:
                    nodeData[x]['weight'] = cost
                    #nodeData[x]['pred'] = nodeData[temp]['pred'] + list(temp)
            heapq.heappush(minHeap,(nodeData[x]['weight'],x))
        heapq.heapify(minHeap)
        temp = minHeap[0][1]
    print("Shortest path is: ", str(nodeData[finish]['weight']))
    

            







#create a fully conected graph with 7 nodes
Graph = {
    'A':{'B': random.randint(1,12), 'C': random.randint(1,12), 'D': random.randint(1,12), 'E': random.randint(1,12), 'F': random.randint(1,12)},
    'B':{'A': random.randint(1,12), 'C': random.randint(1,12), 'D': random.randint(1,12), 'E': random.randint(1,12), 'F': random.randint(1,12), 'G': random.randint(1,12)},
    'C':{'A': random.randint(1,12), 'B': random.randint(1,12), 'D': random.randint(1,12), 'E': random.randint(1,12), 'F': random.randint(1,12), 'G': random.randint(1,12)},
    'D':{'A': random.randint(1,12), 'B': random.randint(1,12), 'C': random.randint(1,12), 'E': random.randint(1,12), 'F': random.randint(1,12), 'G': random.randint(1,12)},
    'E':{'A': random.randint(1,12), 'B': random.randint(1,12), 'C': random.randint(1,12), 'D': random.randint(1,12), 'F': random.randint(1,12), 'G': random.randint(1,12)},
    'F':{'A': random.randint(1,12), 'B': random.randint(1,12), 'C': random.randint(1,12), 'D': random.randint(1,12), 'E': random.randint(1,12), 'G': random.randint(1,12)},
    'G':{'A': random.randint(1,12), 'B': random.randint(1,12), 'C': random.randint(1,12), 'D': random.randint(1,12), 'E': random.randint(1,12), 'F': random.randint(1,12)},
        }

start = 'A'
finish = 'G'
print(Graph)
dijsktra(Graph,start,finish)



