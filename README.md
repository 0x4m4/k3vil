# k3vil
The provided project code showcases a program that simulates ransomware behavior by encrypting files and changing their extensions to "k3vil". Additionally, it includes a decryption process that utilizes a linked list as a key to unlock the encrypted files. The code also incorporates functionality to change the desktop wallpaper using the Windows API.

The central component of the project is the K3vil class, which encompasses the ransomware and decryption functionalities. The ransom function iterates through directories, encrypting files by altering their extensions to "k3vil". On the other hand, the decryption function decrypts the files by retrieving the original suffix from each file and renaming it accordingly.

To facilitate the decryption process, a LinkedList class is implemented to store and search for the required decryption key. This class provides methods for inserting elements into the linked list and searching for a specific key value.

In the main function, an instance of the K3vil class is created, with the suffix set to "k3vil". A linked list is initialized to hold the decryption key, and the desktop wallpaper is changed using the Windows API. The user is then prompted to choose between initiating the ransomware (encryption) or the decryption process. In the case of decryption, the user is asked to enter the provided key. If the correct key is entered and found in the linked list, the program proceeds to decrypt the files. Otherwise, an incorrect password message is displayed.

It's important to note that this code serves solely as a demonstration and should not be utilized for malicious purposes. Ransomware attacks are illegal and unethical, and this code should not be used for any harmful activities.
