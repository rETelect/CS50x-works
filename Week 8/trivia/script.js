document.addEventListener('DOMContentLoaded', function() {


    let buttons = document.querySelectorAll('.choice');


    buttons.forEach(button => {
        button.addEventListener('click', function() {

            let feedback = document.querySelector('#feedback1');

            if (button.innerHTML === '5') {
                button.style.backgroundColor = 'green';
                feedback.innerHTML = 'Correct!';
                feedback.style.color = 'green';
            } else {
                button.style.backgroundColor = 'red';
                feedback.innerHTML = 'Incorrect';
                feedback.style.color = 'red';
            }
        });
    });


    document.querySelector('#check').addEventListener('click', function() {
        let input = document.querySelector('input');
        let feedback = document.querySelector('#feedback2');


        if (input.value.toLowerCase() === 'switzerland') {
            input.style.backgroundColor = 'green';
            feedback.innerHTML = 'Correct!';
            feedback.style.color = 'green';
        } else {
            input.style.backgroundColor = 'red';
            feedback.innerHTML = 'Incorrect';
            feedback.style.color = 'red';
        }
    });

});
