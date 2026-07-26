const worker = new Worker("worker.js");

worker.postMessage("StartWork");
worker.onmessage = (event) =>{
    console.log(event.data);
}

