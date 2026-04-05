import socket

def mulai_klien():
    host = 'localhost'
    port = 12345

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as soket_klien:
        soket_klien.connect((host, port))
        print("Tersambung ke server.")

        try:
            while True:
                pesan = input("Masukkan teks untuk diproses (ketik 'exit' untuk keluar): ")
                if pesan.lower() == 'exit':
                    break

                soket_klien.sendall(pesan.encode())
                respon = soket_klien.recv(1024)
                print("Respon dari server:", respon.decode())

        except ConnectionResetError:
            print("Server memutuskan koneksi")
        except KeyboardInterrupt:
            print("\nKlien dimatikan...")

if __name__ == "__main__":
    mulai_klien()
