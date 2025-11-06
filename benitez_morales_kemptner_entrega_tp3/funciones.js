document.addEventListener('DOMContentLoaded', function() {

  const lightbox = document.getElementById('lightbox');
  const imagenLightbox = document.getElementById('imagen-lightbox');
  const cerrar = document.querySelector('.cerrar-lightbox');
  const miniaturas = document.querySelectorAll('.miniatura');

  function cerrarLightbox() {
    if (lightbox) { 
      lightbox.classList.remove('lightbox-visible');
      lightbox.classList.add('lightbox-oculto');
    }
  }

  if (miniaturas.length > 0 && lightbox && imagenLightbox && cerrar) {

    miniaturas.forEach(function(miniatura) {
      miniatura.addEventListener('click', function(event) {
        event.preventDefault(); 
        const imgSrc = miniatura.querySelector('img').src;
        imagenLightbox.src = imgSrc;
        lightbox.classList.remove('lightbox-oculto');
        lightbox.classList.add('lightbox-visible');
      });
    });

    cerrar.addEventListener('click', function() {
      cerrarLightbox();
    });

    lightbox.addEventListener('click', function(event) {
      if (event.target === lightbox) { 
        cerrarLightbox();
      }
    });
  } 

  // codigo contacto


  const contactForm = document.getElementById('formulario');

  if (contactForm) {
    
    contactForm.addEventListener('submit', function(event) {
      
      event.preventDefault(); 

      const nombre = document.getElementById('nombre').value;
      const apellido = document.getElementById('apellido').value;
      const email = document.getElementById('email').value;

      if (nombre.trim() === '' || apellido.trim() === '' || email.trim() === '') {
        alert('Por favor, completá todos los campos obligatorios (*).');
      } else {
        
        window.open('mailto:benitez.barbara05@gmail.com');

        window.location.href = 'pagina_agradecimiento.html';
      }
    });
  } 

}); 