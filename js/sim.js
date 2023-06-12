class Sim {
  constructor() {
    this.peeps = [];
    this.conns = [];
    this.activeConn = null;
    this.buildSim();
    window.addEventListener("pointerdown", this.onPointerDown.bind(this));
    window.addEventListener("pointermove", this.onPointerMove.bind(this));
    window.addEventListener("pointerup", this.onPointerUp.bind(this));
    //Same maar voor tablet
    // window.addEventListener("touchstart", this.onTouchStart.bind(this));
    // window.addEventListener("touchmove", this.onTouchMove.bind(this));
    // window.addEventListener("touchend", this.onTouchEnd.bind(this));
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
  // connectionExists(from, to) {
  //   for (const conn of this.conns) {
  //     if (conn.from === from && conn.to === to) {
  //       return true;
  //     }
  //   }
  //   return false;
  // }
  // checkAndCreateConnection(from, targetPeep) {
  // 	for (let i = 0; i < this.conns.length; i++) {
  // 		if ((this.conns[i].from.x == from.x && this.conns[i].to.x == targetPeep.x) || (this.conns[i].from.x == targetPeep.x && this.conns[i].to.x == from.x)) {
  // 			this.removeConnection(i);
  // 		}
  // 	}
  //   	this.makeNewConnection(from, targetPeep);
  // }

  // /*Connectie verwijderen*/
  // removeConnection(i) {
  // 	this.conns.splice(i, 1);
  // }

  /* Maak nieuwe connectie als deze valide is */
  createConnectionIfValid(from, targetPeep) {
    if (from.x !== targetPeep.x && targetPeep.x > from.x) {
      this.makeNewConnection(from, targetPeep);
    }
  }

  /*Als de connectie al bestaat, connectie verwijderen*/
  removeConnectionIfExists(from, targetPeep) {
    for (let i = 0; i < this.conns.length; i++) {
      if (
        (this.conns[i].from.x == from.x &&
          this.conns[i].to.x == targetPeep.x) ||
        (this.conns[i].from.x == targetPeep.x && this.conns[i].to.x == from.x)
      ) {
        this.conns.splice(i, 1);
      }
    }
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

  /* Start met maken van connectie indien valide */
  startConnectionIfValid(e, peep) {
    if (this.conns.length == 0) {
      this.startConnection(e, peep);
    }
    for (let i = 0; i < this.conns.length; i++) {
      if (this.conns[i].to.x == peep.x && this.conns[i].to.y == peep.y) {
        this.startConnection(e, peep);
      }
    }
  }

  startConnection(e, peep) {
    peep.active = true;
    this.activeConn = new Conn({
      from: peep,
      to: {
        x: e.clientX,
        y: e.clientY,
      },
    });
  }

  /*Aan en af klikken van Peeps
Om ze actief te maken*/
  onPointerDown(e) {
    e.preventDefault();
    const peep = this.hitTest(e.clientX, e.clientY);
    if (peep) {
      // console.log(peep);
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
  //   onTouchStart(e) {
  //     const touch = e.touches[0]; // Get the first touch point
  //     const peep = this.hitTest(touch.clientX, touch.clientY);
  //     if (peep) {
  //       peep.active = !peep.active;
  //       this.activeConn = new Conn({
  //         from: peep,
  //         to: {
  //           x: touch.clientX,
  //           y: touch.clientY,
  //         },
  //       });
  //     }
  //   }

  onPointerMove(e) {
    this.mouseX = e.clientX;
    this.mouseY = e.clientY;
    if (this.activeConn) {
      this.activeConn.to = {
        x: e.clientX,
        y: e.clientY,
      };
    }
  }
  //   onTouchMove(e) {
  //     const touch = e.touches[0]; // Get the first touch point
  //     this.mouseX = touch.clientX;
  //     this.mouseY = touch.clientY;
  //     if (this.activeConn) {
  //       this.activeConn.to = {
  //         x: touch.clientX,
  //         y: touch.clientY,
  //       };
  //     }
  //   }

  /*Hier wordt ook nieuwe connectie gemaakt*/
  onPointerUp(e) {
    for (const peep of this.peeps) {
      peep.active = false;
    }
    if (this.activeConn) {
      const targetPeep = this.hitTest(e.clientX, e.clientY);
      if (targetPeep) {
        // if (!this.connectionExists(this.activeConn.from, targetPeep)) {
        //   this.makeNewConnection(this.activeConn.from, targetPeep);
        this.removeConnectionIfExists(this.activeConn.from, targetPeep);
        this.createConnectionIfValid(this.activeConn.from, targetPeep);
        this.updatePhysicalInterface();
        targetPeep.active = true;
      }
    }

    this.activeConn = null;
  }
  //   onTouchEnd(e) {
  //     for (const peep of this.peeps) {
  //       peep.active = false;
  //     }
  //     if (this.activeConn) {
  //       const touch = e.changedTouches[0]; // Get the first touch point that ended
  //       const targetPeep = this.hitTest(touch.clientX, touch.clientY);
  //       if (targetPeep) {
  //         this.removeConnectionIfExists(this.activeConn.from, targetPeep);
  //         this.createConnectionIfValid(this.activeConn.from, targetPeep);
  //         targetPeep.active = true;
  //       }
  //     }

  //     this.activeConn = null;
  //   }

  /*Tekenen Peeps*/
  buildSim() {
    this.peeps = [];
    this.peeps.push(
      new Peep({
        x: 370,
        y: 190,
        label: "enkel de\nmannelijke titel",
        index: 0,
        command: "m",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 370,
        y: 275,
        label: "de mannelijke en\nvrouwelijke titel",
        index: 0,
        command: "b",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 560,
        y: 190,
        label: "jongens",
        index: 1,
        command: "b",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 560,
        y: 275,
        label: "meisjes",
        index: 1,
        command: "g",
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
        index: 2,
        command: "6",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 750,
        y: 275,
        label: "7 jaar",
        index: 2,
        command: "7",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 750,
        y: 360,
        label: "8 jaar",
        index: 2,
        command: "8",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 750,
        y: 445,
        label: "9 jaar",
        index: 2,
        command: "9",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 750,
        y: 530,
        label: "10 jaar",
        index: 2,
        command: "10",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 750,
        y: 615,
        label: "11 jaar",
        index: 2,
        command: "11",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 750,
        y: 700,
        label: "12 jaar",
        index: 2,
        command: "12",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 940,
        y: 190,
        label: "enkel mannen",
        index: 3,
        command: "o",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 940,
        y: 275,
        label: "voornamelijk mannen",
        index: 3,
        command: "m",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 940,
        y: 360,
        label: "zowel mannen als vrouwen",
        index: 3,
        command: "b",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 940,
        y: 445,
        label: "voornamelijk vrouwen",
        index: 3,
        command: "w",
        active: false,
        sim: this,
      })
    );

    this.peeps.push(
      new Peep({
        x: 940,
        y: 530,
        label: "enkel vrouwen",
        index: 3,
        command: "f",
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
    //console.log(this.conns);
  }

  updatePhysicalInterface() {
    console.log(this.conns);
    let command = ["?", "?", "?", "?"];
    for (const conn of this.conns) {
      const from = conn.from;
      const to = conn.to;
      command[from.index] = from.command;
      command[to.index] = to.command;
    }

    command = command.join("");
    console.log(command);
    if (command.includes("?")) {
      client.publish("chat", "rrrr");
      return;
    }

    client.publish("chat", command);
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
