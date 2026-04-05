import socket

# Membuat socket UDP
clientSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Menentukan alamat server
serverName = '127.0.0.1'
serverPort = 12000

# Mendapatkan input dari pengguna
message = input("Masukkan pesan: ")

# Mengirim pesan ke server
clientSocket.sendto(message.encode(), (serverName, serverPort))
print(f"Mengirim pesan ke server: {message}")

# Menerima balasan dari server
modifiedMessage, serverAddress = clientSocket.recvfrom(2048)
print("\nBalasan dari server:\n" + modifiedMessage.decode())

# Menutup socket client
clientSocket.close()
