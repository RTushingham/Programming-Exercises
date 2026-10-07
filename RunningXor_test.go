package exercises

import (
    "testing"
)

func TestGetRunningXor(t *testing.T) {
    manual := func( last_value int ) int {
        running_xor := 0
        for Index := range( last_value+1 ){
            running_xor ^= Index
        }
        return running_xor
    }

    test_count := 0
    for Index := range( 160 ){
        if getRunningXor(Index) != manual(Index) {
            t.Error()
        }
        test_count += 1
    }

    if test_count != 160 {
        t.Error()
    }
}
