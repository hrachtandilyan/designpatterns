class Laptop {
  constructor(options) {
    this.name = options?.name || '';
    this.hdd = options?.hdd || 0;
    this.ram = options?.ram || 0;
  }
}

module.exports = Laptop;
