package exercises

import (
    "testing"
)

func TestMissingNumber(t *testing.T) {
    data := []int{ 3,0,1 }
	expected := 2
    res := missingNumber(data)
    if res != expected {
        t.Errorf(`function = %v, want match for %v`, res, expected)
    }
	
	data = []int{ 0,1 }
	expected = 2
    res = missingNumber(data)
    if res != expected {
        t.Errorf(`function = %v, want match for %v`, res, expected)
    }
	
	data = []int{ 9,6,4,2,3,5,7,0,1 }
	expected = 8
    res = missingNumber(data)
    if res != expected {
        t.Errorf(`function = %v, want match for %v`, res, expected)
    }
	
	data = []int{ 1 }
	expected = 0
    res = missingNumber(data)
    if res != expected {
        t.Errorf(`function = %v, want match for %v`, res, expected)
    }
	
	data = []int{ 1,2 }
	expected = 0
    res = missingNumber(data)
    if res != expected {
        t.Errorf(`function = %v, want match for %v`, res, expected)
    }
}

