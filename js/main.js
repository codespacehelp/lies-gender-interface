/*Hier wordt het in gang getrokken
Hier koppeling leggen tussen canvas in html en js*/
let sim, canvas, ctx;

const IMAGES = {
  eyes: "img/eyes.png",
  blink: "img/blink.png",
  face: "img/face.png",
  faceActive: "img/face-active.png",
};

/*De IMAGES van hierboven worden op voorhand geladen*/
function preloadImages() {
  return Promise.all(
    Object.values(IMAGES).map((src) => {
      return new Promise((resolve, reject) => {
        const img = new Image();
        img.onload = () => resolve(img);
        img.onerror = reject;
        img.src = src;
      });
    })
  );
}

/*Aangeven om te wachten tot de beelden zijn geladen
OP het einde moet animate staan, om het effectief te tekenen*/
function main() {
  preloadImages().then((loadedImages) => {
    Object.keys(IMAGES).forEach((key, index) => {
      IMAGES[key] = loadedImages[index];
    });

    sim = new Sim();

    canvas = document.getElementById("sim");
    ctx = canvas.getContext("2d");

    animate();
  });
}

function animate() {
  ctx.clearRect(0, 0, canvas.width, canvas.height);
  sim.update();
  sim.draw(ctx);
  window.requestAnimationFrame(animate);
}

/*button text*/
var isTextModified = false; // Initial state

function changeText() {
  var buttonElement = document.getElementById("button1");
  var textElements = document.getElementsByClassName("Text1");
  if (buttonElement.textContent == "Let me start over!") {
    location.reload();
  }

  for (var i = 0; i < textElements.length; i++) {
    if (
      textElements[i].innerHTML ===
      "The data vase shows the results - or the data base (got it?!) - of a linguistic intervention. <br> Vervecken looked into why stereotypically male jobs are so often seen as approriate for only, <br> or at least mostly, men. <br><br> He figured out that if one addresses a child with both the male and female job title, <br> instead of only the male job title, <br> this child will find men and women more equally capable to do the job.<br><br>"
    ) {
      textElements[i].innerHTML =
        "The paper legend shows you how to read the vase. <br> HOWEVER, With me as your guide, you can also search for specific information on the vase itself! <br><br> Make sentences by connecting one person from each column with the next.<br> The lights show you where to look. What will you find? Excitement!<br><br>"; // Update the text
      buttonElement.textContent = "Let me start over!"; // Update the button text
    } else if (
      textElements[i].innerHTML ===
      "The paper legend shows you how to read the vase. <br> HOWEVER, With me as your guide, you can also search for specific information on the vase itself! <br><br> Make sentences by connecting one person from each column with the next.<br> The lights show you where to look. What will you find? Excitement!<br><br>"
    ) {
      textElements[i].innerHTML =
        "Have you ever heard of the butterfly effect? <br> Or how small changes can lead to great progress.<br> Well, get ready, because you're about to learn something! <br><br> Researcher Dries Vervecken went to investigate and discovered that <b>gender-equal job descriptions</b> in gendered langauges (such as Dutch, duh) have a major effect on children's career interests. <br><br>";
      buttonElement.textContent = "No way. Prove it!"; // Revert back to the original button text
    } else {
      textElements[i].innerHTML =
        "The data vase shows the results - or the data base (got it?!) - of a linguistic intervention. <br> Vervecken looked into why stereotypically male jobs are so often seen as approriate for only, <br> or at least mostly, men. <br><br> He figured out that if one addresses a child with both the male and female job title, <br> instead of only the male job title, <br> this child will find men and women more equally capable to do the job.<br><br>"; // Revert back to the original text
      buttonElement.textContent = "You're kidding?!"; // Revert back to the original button text
    }
  }
}

main();

//Connection with Shifter
const client = mqtt.connect(
  // "wss://prickleking364:EoAqmtU9W9XI9fbR@prickleking364.cloud.shiftr.io",
  "wss://algorithmicgaze:MMtAlPplCmwWUyqR@algorithmicgaze.cloud.shiftr.io",
  {
    clientId: "lies-web",
  }
);

client.on("connect", function () {
  console.log("connected!");
  client.subscribe("lies");
  client.publish("lies", "rrrr"); //PROBLEM! DONT SEND TO CHAT BUT TO ADRUINO
});

client.on("message", function (topic, message) {
  console.log(topic + ": " + message.toString());
});

// ADD BUTTON THAT ALLOWS TO ENTER FULL SCREEN MODE
function initFullscreenButton() {
  function removeFullscreenButton() {
    const fullscreenEl = document.querySelector(".fullscreen");
    if (fullscreenEl) {
      fullscreenEl.parentElement.removeChild(fullscreenEl);
    }
  }

  const fullscreenEl = document.querySelector(".fullscreen");
  const buttonEl = document.createElement("button");
  buttonEl.className = "fullscreen__button";
  buttonEl.textContent = "Fullscreen";
  buttonEl.addEventListener("click", () => {
    _requestFullscreen();
    removeFullscreenButton();
  });
  fullscreenEl.appendChild(buttonEl);
  setTimeout(removeFullscreenButton, 5000);
  window.addEventListener("keypress", (e) => {
    if (e.key === "f") {
      _requestFullscreen();
      removeFullscreenButton();
    }
  });
}

function _requestFullscreen() {
  const element = document.documentElement;
  if (element.requestFullscreen) {
    element.requestFullscreen();
  } else if (element.mozRequestFullScreen) {
    // Firefox
    element.mozRequestFullScreen();
  } else if (element.webkitRequestFullscreen) {
    // Chrome, Safari and Opera
    element.webkitRequestFullscreen();
  } else if (element.msRequestFullscreen) {
    // IE/Edge
    element.msRequestFullscreen();
  }
}

// STOP SCROLLING AND ZOOMING

// Prevent default touch actions that might cause scrolling
document.addEventListener(
  "touchmove",
  function (event) {
    event.preventDefault();
  },
  { passive: false }
);

// Prevent pinch to zoom
document.addEventListener("gesturestart", function (event) {
  event.preventDefault();
});

initFullscreenButton();
