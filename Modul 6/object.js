var objek_kosong = {};

var mobil = {
    "warna-badan": "merah",
    "nomor-polisi": "B 1234 ABC",
    "jumlah_roda": 4,
}

var jadwal = {
    platfrom: 34,
    tujuan: {
        kode_kota: "JKT",
        nama_kota: "Jakarta",
    }
};

console.log("warna mobil: " + mobil["warna-badan"]);
console.log("kota tujuan: " + jadwal.tujuan.nama_kota);
