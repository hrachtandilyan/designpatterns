class SmartPhone {
  constructor(options) {
    this.name = options?.name || '';
    this.hdd = options?.hdd || 0;
    this.ram = options?.ram || 0;
    this.network = options?.network || '4g';
    this.color = options?.color || 'black';
  }
}

module.exports = SmartPhone;
