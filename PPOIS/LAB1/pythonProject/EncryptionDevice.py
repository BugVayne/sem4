from Algorythm import Algorythm
from Data import Data
from EncryptedData import EncryptedData
from KeyClass import Key


def menu():
    print("--------------- Encryption device ------------------")
    print("Enter a key for encrypting data using caesar encryption")
    device = EncryptionDevice(Algorythm("Caesar", Key(int(input()))))
    choice: int = None
    while choice != 8:
        print("1 - enter a sentence for encrypting\n"
              "2 - encrypt data\n"
              "3 - show encrypted data\n"
              "4 - decipher encrypted data\n"
              "5 - show data\n"
              "6 - analyze caesars encryption algorythm\n"
              "7 - manage key\n"
              "8 - exit\n")
        choice = int(input())
        if choice == 1:
            print("Enter data -> ")
            data = Data(input())
            device.set_data(data)
        elif choice == 2:
            device.encrypt_data()
            print("data encrypted")
        elif choice == 3:
            device.show_encrypted_data()
        elif choice == 4:
            device.decipher_data()
        elif choice == 5:
            device.show_original_data()
        elif choice == 6:
            device.analyze_algorythm()
        elif choice == 7:
            device.algorythm.manage_key()
        print("--------------------")
    print("bye bye")


class EncryptionDevice:
    __doc__ = "device uses algorythm to encrypt data"
    __data: Data = Data("")
    __algorythm: Algorythm = None
    __en_data: EncryptedData = EncryptedData("")

    def __init__(self, algorythm_: Algorythm):
        self.algorythm = algorythm_

    def set_data(self, data: Data):
        self.__data = data

    def encrypt_data(self):
        self.__en_data.data = self.algorythm.caesar_encryption(self.__data.data, bool(0))

    def show_encrypted_data(self):
        print("Encrypted Data: ", self.__en_data.data)

    def decipher_data(self):
        print("Deciphered Data: ", self.algorythm.caesar_encryption(self.__en_data.data, bool(1)))

    def show_original_data(self):
        print("Original Data: ", self.__data.data)

    def analyze_algorythm(self):
        print("Code was broken in ", self.algorythm.caesar_analyze(self.__en_data.data, self.__data.data), "iterations")
