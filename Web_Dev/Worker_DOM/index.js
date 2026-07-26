const worker = new Worker("worker.js");

worker.postMessage("Start work!");

worker.onmessage = (event) => {
    console.log(event.data);


    if (!users || users.length === 0) {
        usersDiv.textContent = "No users found.";
        return;
    }
    
    const usersDiv = document.getElementById("users");
    usersDiv.innerHTML = ""; 

    event.data.users.forEach(user => {
        const p = document.createElement("p");
        p.textContent = `${user.firstName} ${user.lastName} - "Active"`;
        usersDiv.appendChild(p);
    });
};