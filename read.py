import math

HDR_MARK = 3200
HDR_SPACE = 1600

BIT_MARK = 420
SPACE_0 = 410
SPACE_1 = 1200

print('test')

def binaryStringToHex(val):
    return hex(int(val, 2))

def isVal(expected, value):
    return math.isclose(abs(int(expected)), abs(int(value)), rel_tol=0.30)

def isHdr(val1, val2):
    return (isVal(HDR_MARK, val1) and isVal(HDR_SPACE, val2))

def readRawData(strinRawData):
    rawDataArray = strinRawData.split(',')
    if(not isHdr(rawDataArray[0], rawDataArray[1])):
        raise ValueError("HDR not found")

    output = ''    
    lastBitMark = False    
    for i in range(2, len(rawDataArray)-1):
      if(lastBitMark):
         if(isVal(SPACE_0, rawDataArray[i])):
              output += '0'
         elif (isVal(SPACE_1, rawDataArray[i])):
              output += '1'
         else: raise ValueError("bit invalid: "+rawDataArray[i])    

         lastBitMark = False
      else:
          if(not isVal(BIT_MARK, rawDataArray[i])): raise ValueError("bitmark not found: "+rawDataArray[i])
          lastBitMark = True

    return output
      
    
rawData = '3176, -1616, 424, -1208, 384, -1224, 424, -368, 448, -368, 408, -392, 404, -1240, 424, -368, 412, -388, 408, -1240, 424, -1188, 388, -400, 452, -1200, 388, -392, 404, -404, 448, -1204, 364, -1244, 424, -368, 448, -1188, 388, -1236, 428, -372, 404, -412, 388, -1236, 424, -372, 408, -408, 388, -1240, 424, -368, 412, -388, 408, -404, 448, -364, 448, -1188, 388, -400, 448, -368, 448, -368, 408, -408, 388, -404, 448, -364, 448, -372, 408, -408, 388, -404, 444, -368, 448, -368, 412, -408, 384, -408, 444, -364, 452, -368, 408, -408, 392, -400, 448, -364, 452, -1184, 388, -404, 448, -364, 448, -368, 412, -1220, 420, -1208, 388, -408, 392, -400, 448, -1204, 388, -1220, 424, -1208, 388, -408, 384, -1244, 424, -1188, 384, -408, 444, -368, 448, -368, 412, -404, 388, -1240, 424, -372, 408, -408, 388, -404, 444, -368, 448, -368, 412, -408, 384, -408, 444, -368, 448, -368, 408, -392, 404, -404, 444, -372, 444, -372, 408, -408, 388, -404, 448, -364, 448, -372, 408, -388, 408, -400, 448, -368, 448, -368, 408, -1204, 440, -1208, 388, -1224, 420, -1208, 388, -1220, 424, -1204, 388, -1224, 420, -1208, 388, -408, 388, -1240, 424, -1188, 388, -1236, 428, -368, 412, -408, 388, -1236, 424, -1188, 388, -404, 448, -364, 452, -368, 408, -1220, 424, -368, 448, -368, 412, -1220, 420, -1208, 388, -1220, 424, -1208, 388, -408, 384, -1244, 424, -1188, 388, -1236, 428, -1184, 388, -1240, 424, -1188, 388, -1240, 424, -1188, 384, -1240, 428, -1188, 384, -1240, 428, -1184, 388, -1240, 424, -1188, 388, -1236, 424, -1188, 388, -1240, 424, -1188, 388, -1236, 428, -1188, 388, -1236, 428, '

print(binaryStringToHex(readRawData(rawData)).upper() )











