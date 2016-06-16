import numpy as np

def readNumber(line, index):
    number = 0
    while index < len(line) and line[index].isdigit():
        number = number * 10 + int(line[index])
        index += 1
        if index < len(line) and line[index] == '.':
            index += 1
            keta = 0.1
            while index < len(line) and line[index].isdigit():
                number += int(line[index]) * keta
                keta *= 0.1
                index += 1
    token = {'type': 'NUMBER', 'number': number}
    return token, index

def readPlus(line, index):
    token = {'type': 'PLUS'}
    return token, index + 1

def readMinus(line, index):
    token = {'type': 'MINUS'}
    return token, index + 1

def readTimes(line, index):
    token = {'type': 'TIMES'}
    return token, index + 1

def readDiv(line, index):
    token = {'type': 'DIV'}
    return token, index + 1

def tokenize(line):
    tokens = []
    index = 0
    while index < len(line):
        if line[index].isdigit():
            (token, index) = readNumber(line, index)
        elif line[index] == '+':
            (token, index) = readPlus(line, index)
        elif line[index] == '-':
            (token, index) = readMinus(line, index)
        elif line[index] == '*':
            (token, index) = readTimes(line, index)
        elif line[index] == '/':
            (token, index) = readDiv(line, index)
        else:
            print 'Invalid character found: ' + line[index]
            exit(1)
        tokens.append(token)
    return tokens

def evaluate(tokens):
    answer = 0
    tokens2 = []
    tokens.insert(0, {'type': 'PLUS'}) # Insert a dummy '+' token
    index = 1
    index2 = 1

    while index < len(tokens):
        if tokens[index]['type'] == 'NUMBER':
            tokens2.insert(index2, {'type': 'NUMBER', 'number': tokens[index]['number']})
            if tokens[index - 1]['type'] == 'PLUS':
                tokens2.insert(index2 - 1, {'type': 'PLUS'})
            elif tokens[index - 1]['type'] == 'MINUS':
                tokens2.insert(index2 - 1, {'type': 'MINUS'})
            elif tokens[index - 1]['type'] == 'TIMES':
                tokens2.insert(index2 - 2, {'type': 'NUMBER', 'number': tokens2[index2 - 2]['number'] * tokens[index]['number']})
                del tokens2[index2]
                del tokens2[index2 - 1]
                index2 -= 2
            elif tokens[index - 1]['type'] == 'DIV':
                tokens2.insert(index2 - 2, {'type': 'NUMBER', 'number': tokens2[index2 - 2]['number'] / tokens[index]['number']})
                del tokens2[index2]
                del tokens2[index2 - 1]
                index2 -= 2
            else:
                print 'Invalid syntax'
        index += 1
        index2 += 1

    index2 = 1

    while index2 < len(tokens2):
        if tokens2[index2]['type'] == 'NUMBER':
            if tokens2[index2 - 1]['type'] == 'PLUS':
                answer += tokens2[index2]['number']
            elif tokens2[index2 - 1]['type'] == 'MINUS':
                answer -= tokens2[index2]['number']
            else:
                print 'Invalid syntax2'
        index2 += 1
    return answer

while True:
    print '> ',
    line = raw_input()
    tokens = tokenize(line)
    answer = evaluate(tokens)
    print "answer = %f\n" % answer
