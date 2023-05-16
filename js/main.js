let sim, canvas, ctx;

const IMAGES = {
  eyes: "img/eyes.png",
  face: "img/face.png",
  faceActive: "img/face-active.png",
};

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

async function main() {
  const loadedImages = await preloadImages();
  Object.keys(IMAGES).forEach((key, index) => {
    IMAGES[key] = loadedImages[index];
  });

  sim = new Sim();

  canvas = document.getElementById("sim");
  ctx = canvas.getContext("2d");

  animate();
}

function animate() {
  ctx.clearRect(0, 0, canvas.width, canvas.height);
  sim.update();
  sim.draw(ctx);
  window.requestAnimationFrame(animate);
}

main();
