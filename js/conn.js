/*Lijnverbindingen
Nood aan een van en een to element
Link met SIM houden, om connectie te maken tussen Peeps*/
class Conn {
  constructor(config) {
    this.from = config.from;
    this.to = config.to;
    this.sim = config.sim;
  }

  update() {}

  draw(ctx) {
    ctx.strokeStyle = "#999";
    ctx.lineWidth = 2.5;
    ctx.beginPath(); 
  ctx.moveTo(this.from.x, this.from.y );
  ctx.lineTo(this.to.x , this.to.y );
    ctx.stroke();
  }
}
