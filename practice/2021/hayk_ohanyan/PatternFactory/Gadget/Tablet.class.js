class Tablet {
  constructor(options) {
    this.name = options?.name || '';
    this.hdd = options?.hdd || 0;
    this.ram = options?.ram || 0;
    this.network = options?.network || '5g';
  }
}

module.exports = Tablet;
