window.onload = () =>{
    console.log('hey');
    returnTime();
    check_heartbeat();
}

const check_heartbeat = () => {
  let last_beat = parseInt(document.getElementById("js--heartbeat").innerHTML);

  const general_checkmark = document.getElementById("js--checkmark");
  const checkmark_connection = document.getElementById("js--checkmark_connection");
  const status_text = document.getElementById("status_text");
  const connection_text = document.getElementById("js--connection-text");

  let now = Date.now()/1000;
  let seconds_since_beat = (now-last_beat);

  console.log("seconds since last heartbeat "+seconds_since_beat);
  
  if (seconds_since_beat > 60) {
    console.log("heartbeat dead!!!");
    checkmark_connection.innerHTML = "error_outline";
    checkmark_connection.style.color = "red";
    general_checkmark.innerHTML = "error_outline";
    general_checkmark.style.color = "red";
    connec.style.color = "red";
    status_text.innerHTML = "niet naar behoren";
  } 
  else {
    console.log("heartbeat alive!!");
  }
}

const openHistory = () =>{
    const history_card = document.getElementById('js--history_card');
    const card_wrapper = document.getElementsByClassName('card--wrapper');
    history_card.style.opacity = "0"
    history_card.style.display = "block";
    history_card.animate([
        { // from
          opacity: 0,
        },
        { // to
          opacity: 1,
        }
      ], 250);
    history_card.style.opacity = "1"

    card_wrapper[0].style.opacity = "0.5";
    card_wrapper[1].style.opacity = "0.5";
}

closeHistory = () =>{
    const history_card = document.getElementById('js--history_card');
    const card_wrapper = document.getElementsByClassName('card--wrapper');

    history_card.style.opacity = "1";
    history_card.animate([
        { // from
            opacity: 1,
        },
        { // to
            opacity: 0,
        }
    ], 250);
    history_card.style.opacity = "0";
    
    setTimeout(function() {
        history_card.style.display = "none";
      }, 251);

    card_wrapper[0].style.opacity = "1";
    card_wrapper[1].style.opacity = "1";
}

returnTime = () =>{
  const time = document.getElementById('js--time');
  let current = new Date();
  time.innerHTML = current.toLocaleTimeString();
}

hoi = () =>{
    console.log('hoi')
}