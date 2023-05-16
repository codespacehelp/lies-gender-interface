class Conn {
  constructor(config) {
    this.from = config.from;
    this.to = config.to;
    this.sim = config.sim;
  }

  update() {}

  draw(ctx) {
    ctx.strokeStyle = "#999";
    ctx.lineWidth = 5;
    ctx.beginPath();
    ctx.moveTo(this.from.x, this.from.y);
    ctx.lineTo(this.to.x, this.to.y);
    ctx.stroke();
  }
}
