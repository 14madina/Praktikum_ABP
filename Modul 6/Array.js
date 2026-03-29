var data = ["satu", 2, true];

console.log("Elemen indeks ke-0:" + data[0]);
console.log("Elemen indeks ke-1:" + data[1]);

data.push("baru");
console.log("Setelah push: " + data);

data.pop();
console.log("Setelah pop: " + data);

var arr2 = [["satu", "dua"], ["tiga", "empat"]];
console.log("Akses array 2D: " + arr2[0][1]);