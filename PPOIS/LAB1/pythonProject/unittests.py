import unittest
from EncryptionDevice import EncryptionDevice
from Algorythm import Algorythm
from KeyClass import Key
from Data import Data
from unittest.mock import patch

class EncryptionDeviceTest(unittest.TestCase):
    def test_data_storing(self):
        device = EncryptionDevice(Algorythm("Caesar", Key(3)))
        test_str: str = "abc"
        device.set_data(Data(test_str))
        self.assertEqual(test_str, device.get_data())

    def test_encrypting(self):
        device = EncryptionDevice(Algorythm("Caesar", Key(3)))
        device.set_data(Data("abc"))
        device.encrypt_data()
        self.assertEqual("def", device.get_encrypted_data())

    def test_data_deciphering(self):
        device = EncryptionDevice(Algorythm("Caesar", Key(3)))
        device.set_data(Data("abc"))
        device.encrypt_data()
        device.decipher_data()
        self.assertEqual("abc", device.get_data())

    def test_security_correct(self):
        device = EncryptionDevice(Algorythm("Caesar", Key(3)))
        with patch('builtins.input', return_value="12qw"):
            result = device.security()
        self.assertTrue(result)

    def test_security_incorrect(self):
        device = EncryptionDevice(Algorythm("Caesar", Key(3)))
        with patch('builtins.input', return_value="purr purr purr"):
            result = device.security()
        self.assertFalse(result)




if __name__ == '__main__':
    unittest.main()
