package exercises

func getRunningXor(last_value int) int {
    switch last_value % 4 {
    case 0:
        return last_value
    case 1:
        return 1
    case 2:
        return last_value+1
    case 3:
        return 0
    }

    return -1
}

