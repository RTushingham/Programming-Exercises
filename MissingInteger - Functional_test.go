package exercises

import (
    "testing"
)

func TestMissingNumberFunctional(t *testing.T) {
    data := []int{ 3,0,1 }
	expected := 2
    res := missingNumberFunctional(data)
    if res != expected {
        t.Error()
    }
	
	data = []int{ 0,1 }
	expected = 2
    res = missingNumberFunctional(data)
    if res != expected {
        t.Error()
    }
	
	data = []int{ 9,6,4,2,3,5,7,0,1 }
	expected = 8
    res = missingNumberFunctional(data)
    if res != expected {
        t.Error()
    }
	
	data = []int{ 1 }
	expected = 0
    res = missingNumberFunctional(data)
    if res != expected {
        t.Error()
    }
	
	data = []int{ 1,2 }
	expected = 0
    res = missingNumberFunctional(data)
    if res != expected {
        t.Error()
    }
}

