import socket
from datetime import datetime

def proses_data(data):
    # 1. Balikkan huruf besar/kecil
    diproses = data.swapcase()

    # 2. Hitung jumlah karakter
    jumlah_karakter = f"{len(diproses)} karakter"

    # 3. Hapus spasi di awal/akhir
    diproses = diproses.strip()

    # 4. Tambahkan timestamp
    timestamp = datetime.now().strftime("[%Y-%m-%d %H:%M:%S]")

    # 5. Tambahkan konfirmasi
    konfirmasi = "[Data telah diproses]"

    return f"{diproses} ({jumlah_karakter}) {timestamp} {konfirmasi}"

def mulai_server():
    host = 'localhost'
    port = 12345

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
        server_socket.bind((host, port))
        server_socket.listen()
        print(f"Server TCP siap di {host}:{port}")

        try:
            while True:
                koneksi, alamat = server_socket.accept()
                with koneksi:
                    print(f"Tersambung dengan {alamat}")
                    while True:
                        data = koneksi.recv(1024)
                        if not data:
                            break
                        pesan = data.decode()
                        print(f"Data diterima: {pesan}")
                        respon = proses_data(pesan)
                        koneksi.sendall(respon.encode())

        except KeyboardInterrupt:
            print("\nServer dimatikan...")

if __name__ == "__main__":
    mulai_server()
