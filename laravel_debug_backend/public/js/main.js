window.onload = () =>{
    console.log('hey');
}

openHistory = () =>{
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

hoi = () =>{
    console.log('hoi')
}