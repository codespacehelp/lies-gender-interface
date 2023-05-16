class Sim {
  constructor() {
    this.peeps = [];
    this.conns = [];
    this.activeConn = null;
    this.buildSim();
    window.addEventListener("mousedown", this.onMouseDown.bind(this));
    window.addEventListener("mousemove", this.onMouseMove.bind(this));
    window.addEventListener("mouseup", this.onMouseUp.bind(this));
  }

  hitTest(mouseX, mouseY) {
    for (const peep of this.peeps) {
      const dx = peep.x - mouseX;
      const dy = peep.y - mouseY;
      const dist = Math.sqrt(dx * dx + dy * dy);
      if (dist < 50) {
        return peep;
      }
    }
    return null;
  }

  connectionExists(from, to) {
    for (const conn of this.conns) {
      if (conn.from === from && conn.to === to) {
        return true;
      }
    }
    return false;
  }

  makeNewConnection(from, to) {
    this.conns.push(
      new Conn({
        from: from,
        to: to,
      })
    );
  }

  onMouseDown(e) {
    const peep = this.hitTest(e.clientX, e.clientY);
    if (peep) {
      console.log(peep);
      peep.active = !peep.active;
      this.activeConn = new Conn({
        from: peep,
        to: {
          x: e.clientX,
          y: e.clientY,
        },
      });
    }
  }

  onMouseMove(e) {
    this.mouseX = e.clientX;
    this.mouseY = e.clientY;
    if (this.activeConn) {
      this.activeConn.to = {
        x: e.clientX,
        y: e.clientY,
      };
    }
  }

  onMouseUp(e) {
    for (const peep of this.peeps) {
      peep.active = false;
    }
    if (this.activeConn) {
      const targetPeep = this.hitTest(e.clientX, e.clientY);
      if (targetPeep) {
        if (!this.connectionExists(this.activeConn.from, targetPeep)) {
          this.makeNewConnection(this.activeConn.from, targetPeep);
        }
      }
    }

    this.activeConn = null;
  }

  buildSim() {
    this.peeps = [];
    this.peeps.push(
      new Peep({
        x: 100,
        y: 100,
        label: "Enkel mannelijke titel",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 100,
        y: 250,
        label: "Vrouwelijke en mannelijke titel",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 300,
        y: 100,
        label: "Jongens",
        active: false,
        sim: this,
      })
    );

    console.log(this.peeps);

    this.conns = [];
    this.conns.push(
      new Conn({
        from: this.peeps[0],
        to: this.peeps[2],
      })
    );

    console.log(this.conns);
  }

  update() {
    for (const peep of this.peeps) {
      peep.update();
    }
    for (const conn of this.conns) {
      conn.update();
    }
  }

  draw(ctx) {
    for (const conn of this.conns) {
      conn.draw(ctx);
    }
    if (this.activeConn) {
      this.activeConn.draw(ctx);
    }
    for (const peep of this.peeps) {
      peep.draw(ctx);
    }
  }
}
