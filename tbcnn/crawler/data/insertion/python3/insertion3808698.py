def FUNC00(ARG00):
    for VAR00 in range(1, len(ARG00)):
        VAR01 = ARG00[VAR00]
        VAR02 = VAR00 - 1
        while VAR02 >= 0 and ARG00[VAR02] > VAR01:
            ARG00[VAR02 + 1] = ARG00[VAR02]
            VAR02 -= 1
        ARG00[VAR02 + 1] = VAR01
        print(' '.join([str(VAR03) for VAR03 in ARG00]))
VAR04 = int(input())
VAR05 = [int(VAR06) for VAR06 in input().split()]
print(' '.join([str(VAR06) for VAR06 in VAR05]))
FUNC00(VAR05)
