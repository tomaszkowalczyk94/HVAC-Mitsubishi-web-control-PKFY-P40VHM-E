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
      
    
rawData = '''
3204, -1596, 436, -1216, 360, -1224, 444, -372, 440, -376, 412, -388, 404, -1220, 440, -376, 408, -388, 404, -1244, 420, -1192, 388, -400, 444, -1212, 388, -388, 408, -404, 444, -1208, 384, -1224, 420, -372, 448, -1188, 356, -1268, 424, -368, 412, -388, 408, -1240, 416, -376, 412, -408, 384, -1220, 444, -372, 412, -404, 388, -408, 444, -368, 444, -1188, 388, -404, 448, -368, 444, -372, 408, -388, 404, -412, 440, -372, 444, -368, 412, -388, 408, -404, 444, -368, 444, -372, 412, -388, 404, -408, 440, -372, 444, -372, 412, -408, 356, -1268, 396, -400, 412, -388, 376, -1268, 420, -376, 412, -388, 376, -432, 444, -368, 448, -1168, 408, -1240, 392, -1220, 360, -428, 444, -372, 444, -372, 412, -1200, 412, -1216, 408, -408, 360, -432, 444, -372, 440, -376, 412, -1196, 444, -368, 448, -368, 412, -388, 404, -408, 444, -368, 448, -368, 416, -404, 360, -428, 448, -368, 444, -372, 412, -388, 380, -432, 444, -368, 452, -364, 408, -408, 388, -404, 444, -372, 444, -372, 412, -404, 360, -432, 444, -368, 444, -1192, 388, -1216, 444, -1192, 356, -1248, 420, -1216, 356, -1248, 440, -380, 408, -1200, 412, -1216, 408, -408, 388, -1240, 420, -1192, 388, -1216, 444, -1192, 384, -408, 444, -368, 448, -368, 412, -1200, 444, -1184, 412, -1200, 440, -368, 448, -368, 416, -1200, 440, -1188, 408, -1200, 448, -1184, 408, -388, 380, -1244, 448, -1188, 388, -1216, 440, -1196, 384, -1224, 436, -1192, 388, -1216, 444, -1192, 384, -1220, 444, -1192, 388, -1240, 392, -1220, 388, -1216, 448, -1188, 384, -1220, 440, -1192, 384, -1224, 444, -1188, 388, -1240, 392, -1220, 384, -1220, 448, 

'''
#  C4D364840002438C200000FDBC73DFFFFF


print(binaryStringToHex(readRawData(rawData)).upper() )











