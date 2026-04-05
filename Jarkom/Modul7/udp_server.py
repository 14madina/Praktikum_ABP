import socket
from datetime import datetime

# Membuat socket UDP
serverSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
serverPort = 12000

# Bind socket ke alamat dan port
serverSocket.bind(('', serverPort))
print(f"Server berjalan di port {serverPort}...")

while True:
    # Menerima datagram dari client
    message, clientAddress = serverSocket.recvfrom(1024)
    decodedMessage = message.decode()
    print(f"Menerima pesan dari {clientAddress}: {decodedMessage}")

    # Proses 1: Inversi case
    inversed = decodedMessage.swapcase()

    # Proses 2: Hitung jumlah karakter
    jumlah_karakter = len(inversed)

    # Proses 3: Hapus spasi di awal dan akhir
    trimmed = inversed.strip()

    # Proses 4: Tambah timestamp
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

    # Proses 5: Tambah pesan konfirmasi
    modifiedMessage = (
        f"{trimmed}\n"
        f"Jumlah karakter: {jumlah_karakter}\n"
        f"Timestamp: {timestamp}\n"
        f"Data telah diproses"
    )

    # Mengirim balasan ke client
    serverSocket.sendto(modifiedMessage.encode(), clientAddress)
    print(f"Mengirim balasan ke {clientAddress}:\n{modifiedMessage}")
