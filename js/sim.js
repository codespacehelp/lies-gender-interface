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

  /*Hittest om aan te klikken*/
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

  /*Als de connectie al bestaat, geen nieuwe connectie maken*/
  connectionExists(from, to) {
    for (const conn of this.conns) {
      if (conn.from === from && conn.to === to) {
        return true;
      }
    }
    return false;
  }

  /*Om te connecteren met lichtjes
  Zo kan event worden doorgestuurd naar Shifter, om dan naar Arduino te gaan*/
  makeNewConnection(from, to) {
    this.conns.push(
      new Conn({
        from: from,
        to: to,
      })
    );
  }

/*Aan en af klikken van Peeps
Om ze actief te maken*/
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
/*Hier wordt ook nieuwe connectie gemaakt*/
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

/*Tekenen Peeps*/
  buildSim() {
    this.peeps = [];
    this.peeps.push(
      new Peep({
        x: 370,
        y: 190,
        label: "enkel de\nmannelijke titel",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 370,
        y: 275,
        label: "de mannelijke en\nvrouwelijke titel",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 560,
        y: 190,
        label: "jongens",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 560,
        y: 275,
        label: "meisjes",
        active: false,
        sim: this,
      })
    );
    console.log(this.peeps);

    this.peeps.push(
      new Peep({
        x: 750,
        y: 190,
        label: "6 jaar",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 750,
        y: 275,
        label: "7 jaar",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 750,
        y: 360,
        label: "8 jaar",
        active: false,
        sim: this,
      })
    );
  
    this.peeps.push(
      new Peep({
        x: 750,
        y: 445,
        label: "9 jaar",
        active: false,
        sim: this,
      })
    );
  
    this.peeps.push(
      new Peep({
        x: 750,
        y: 530,
        label: "10 jaar",
        active: false,
        sim: this,
      })
    );
  
    this.peeps.push(
      new Peep({
        x: 750,
        y: 615,
        label: "11 jaar",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 750,
        y: 700,
        label: "12 jaar",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 940,
        y: 190,
        label: "enkel mannen",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 940,
        y: 275,
        label: "voornamelijk mannen",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 940,
        y: 360,
        label: "zowel mannen als vrouwen",
        active: false,
        sim: this,
      })
    );
  
    this.peeps.push(
      new Peep({
        x: 940,
        y: 445,
        label: "voornamelijk vrouwen",
        active: false,
        sim: this,
      })
    );
  
    this.peeps.push(
      new Peep({
        x: 940,
        y: 530,
        label: "enkel vrouwen",
        active: false,
        sim: this,
      })
    );
  
    /*Lijn moet na Peeps worden getekend opdat deze achter de Peeps wordt getoond*/
    this.conns = [];
    // this.conns.push(
    //   new Conn({
    //     from: this.peeps[0],
    //     to: this.peeps[2],
    //   })
    // );
    console.log(this.conns);
  }

/*Hier oproepen, gemaakt in Peeps
Gaat animaties en simulaties zo draaien
Zo worden ze elke keer vernieuwd*/
  update() {
    for (const peep of this.peeps) {
      peep.update();
    }
    for (const conn of this.conns) {
      conn.update();
    }
  }

  /*Functie maken om te tekenen
  Deels hier, deels in peeps*/
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
