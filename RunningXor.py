
def getRunningXor( last_value: int ) -> int:
    match( last_value % 4 ):
        case 0:
            return last_value
        case 1:
            return 1
        case 2:
            return last_value+1
        case 3:
            return 0


import unittest

class TestRunningXor(unittest.TestCase):

    def test_running_xor(self):
        def manuallyCreatedRunningXor( last_value: int ) -> int:
            running_xor = 0
            for Index in range( last_value+1 ):
                running_xor ^= Index
            return running_xor

        test_count = 0
        for Index in range( 160 ):
            self.assertEqual( getRunningXor(Index), manuallyCreatedRunningXor(Index) )
            test_count += 1

        self.assertEqual( test_count,160 )
