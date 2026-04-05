var mobil = {
    "warna-badan": "merah",
    "nomor-polisi": "BK1234AB",
    "jumlah_roda": 4
};

// 1. Menggunakan Kurung Siku [] (wajib untuk nama properti ilegal/pakai spasi)
console.log("Warna: " + mobil["warna-badan"]);

// 2. Menggunakan Tanda Titik . (Cara paling umum/legal)
console.log("Roda: " + mobil.jumlah_roda);

// 3. Mengakses properti yang tidak ada (Hasilnya Undefined)
console.log("Kursi: " + mobil.nomor_kursi);

// 4. Mengubah atau menambah nilai properti secara dinamis
mobil.bahan_bakar = "Bensin";
console.log("Bahan Bakar: " + mobil.bahan_bakar);