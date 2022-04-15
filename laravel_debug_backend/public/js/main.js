window.onload = () => {
  returnTime();
  check_heartbeat();
}

//De check_heartbeat wordt gebruikt voor het controleren van de verbinding tussen de arduino en de database. 
//Wanneer de arduino een hartbeat stuurt wordt de database geupdate.
const check_heartbeat = () => {
  let last_beat = parseInt(document.getElementById("js--heartbeat").innerHTML);

  const general_checkmark = document.getElementById("js--checkmark");
  const checkmark_connection = document.getElementById("js--checkmark_connection");
  const status_text = document.getElementById("status_text");
  const connection_text = document.getElementById("js--connection-text");

  let now = Date.now() / 1000;
  let seconds_since_beat = (now - last_beat);

  console.log("seconds since last heartbeat " + seconds_since_beat);

  //Wanneer de heartbeat langer dan 60 seconden voor het laatst ontvangen is wordt er aan de gebruiker aangegeven dat de connectie niet naar behoren werkt. 
  if (seconds_since_beat > 60) {
    console.log("heartbeat dead!!!");
    checkmark_connection.innerHTML = "error_outline";
    // checkmark_connection.style.color = "red";
    checkmark_connection.src = "/img/warning2.png";
    general_checkmark.innerHTML = "error_outline";
    // general_checkmark.style.color = "red";
    general_checkmark.src = "/img/warning2.png";
    connection_text.style.color = "red";
    status_text.innerHTML = "niet naar behoren";
  }
  else {
    console.log("heartbeat alive!!");
  }
}

//De openHistory functie opent het scherm met de laatste ontvangen post.
const openHistory = () => {
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

//De closeHistory sluit het scherm met de laatst ontvangen post.
closeHistory = () => {
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

  setTimeout(function () {
    history_card.style.display = "none";
  }, 251);

  card_wrapper[0].style.opacity = "1";
  card_wrapper[1].style.opacity = "1";
}

//De returnTime functie haalt de huidige tijd op. 
//Met deze tijd wordt er aan de gebruiker aangegeven wanneer er voor het laatst gecontroleerd is of er post is.
returnTime = () => {
  const time = document.getElementById('js--time');
  let current = new Date();
  time.innerHTML = current.toLocaleTimeString();
}