class Peep {
  constructor(config) {
    this.x = config.x;
    this.y = config.y;
    this.label = config.label;
    this.active = !!config.active;
    this.sim = config.sim;
  }

  update() {
    const mx = this.sim.mouseX;
    const my = this.sim.mouseY;
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

  draw(ctx) {
    // ctx.fillRect(this.x - 50, this.y - 50, 100, 100);
    if (this.active) {
      ctx.drawImage(IMAGES.faceActive, this.x - 50, this.y - 50, 100, 100);
    } else {
      ctx.drawImage(IMAGES.face, this.x - 50, this.y - 50, 100, 100);
    }
    ctx.drawImage(
      IMAGES.eyes,
      this.x - 50 + this.faceX,
      this.y - 50 + this.faceY,
      100,
      100
    );
    ctx.textAlign = "center";
    ctx.fillText(this.label, this.x, this.y + 60);
  }
}
