from Solution import Solution
import unittest
from timeout_decorator import timeout

class UnitTest(unittest.TestCase):
    def setUp(self):
        self.__testCases = {1: ([10,2,5,3], True), 2: ([3,1,7,11], False)}
        self.__obj = Solution()
        return super().setUp()
    
    def test_Case_1(self):
        arr, output = self.__testCases[1]
        result = self.__obj.checkIfExist(arr)
        self.assertIsInstance(result, bool)
        self.assertEqual(result, output)

    def test_Case_2(self):
        arr, output = self.__testCases[2]
        result = self.__obj.checkIfExist(arr)
        self.assertIsInstance(result, bool)
        self.assertEqual(result, output)

if __name__ == '__main__':
    unittest.main()