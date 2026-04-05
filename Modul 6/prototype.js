// 1. Membuat objek dasar (Modul 6.3.3)
var mobil = {
    nama: "Mobil",
    jumlahBan: 4
};

// 2. Melakukan penurunan menggunakan Object.create
var truk = Object.create(mobil);

// 3. Menampilkan hasil penurunan
console.log("Nama Truk: " + truk.nama);       // Hasil: Mobil
console.log("Ban Truk: " + truk.jumlahBan);   // Hasil: 4

// 4. Mengubah properti khusus untuk truk
truk.nama = "Truk Gandeng";
console.log("Nama Baru: " + truk.nama);