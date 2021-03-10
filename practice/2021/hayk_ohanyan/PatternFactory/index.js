const GadgetFactory = require('./Factory.class')

const factory = new GadgetFactory()

const gadgets = [
  factory.create('Tablet', {
    name: 'Ipad 4',
    ram: 8,
    hdd: 256,
    network: '4g'
  }),
  factory.create('Laptop', {
    hdd: 1000,
    ram: 16,
    name: 'Asus VivoBook'
  }),
  factory.create('SmartPhone', {
    hdd: 64,
    ram: 4,
    name: 'HTC'
  })
]

console.log(gadgets);
