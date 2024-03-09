import unittest
from EncryptionDevice import EncryptionDevice
from Algorythm import Algorythm
from KeyClass import Key


class EncryptionDeviceTest(unittest.TestCase):
    def test_encrypting(self):
        device = EncryptionDevice(Algorythm("Caesar", Key(int(input()))))

if __name__ == '__main__':
    unittest.main()
