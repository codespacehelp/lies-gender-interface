/*Elementen van Peep die getekend worden;
Configuratiedata*/
class Peep {
  constructor(config) {
    this.x = config.x;
    this.y = config.y;
  /*  this.label = config.label;*/
    this.active = !!config.active;
    this.sim = config.sim;
  }

/*Eyemovement met limitatie*/
  update() {
    // const mx = this.sim.mouseX;
    // const my = this.sim.mouseY;
    this.faceX = (this.sim.mouseX - this.x) / 5;
    this.faceY = (this.sim.mouseY - this.y) / 5;

    const faceMag = Math.sqrt(
      this.faceX * this.faceX + this.faceY * this.faceY
    );
    const maxDistance = 5;

    if (faceMag > maxDistance) {
      this.faceX = this.faceX * (maxDistance / faceMag);
      this.faceY = this.faceY * (maxDistance / faceMag);
    }
  }

  /*Draw functie maken
  Dit kan omdat de IMAGES in MAIN worden geladen
  EN IF active, dan andere image*/
  draw(ctx) {
    // ctx.fillRect(this.x - 50, this.y - 50, 50, 50);
    if (this.active) {
      ctx.drawImage(IMAGES.faceActive, this.x - 25, this.y - 25, 50, 50);
    } else {
      ctx.drawImage(IMAGES.face, this.x - 25, this.y - 25, 50, 50);
    }
    ctx.drawImage(
      IMAGES.eyes,
      this.x - 25 + this.faceX,
      this.y - 25 + this.faceY,
      50, 50
    );
  /*  ctx.fillText(this.label, this.x, this.y + 15);*/
    ctx.textAlign = "center";
  }
}
