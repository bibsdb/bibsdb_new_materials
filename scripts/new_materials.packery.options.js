

(function($) {
  'use strict';

  var BibsdbOpenPlatformList = (function() {

    var running_request = false;
    var full = false;

     /**
     * Private: Makes an ajax call to the server to get more content for the
     * list. The query node nid and the offset is sent along with the ajax request.
     */
     function _load_more() {
      var items = $('.open-platform-item-list').packery('getItemElements');
      _fetch(items.length);
    }

     /**
     * Private: Updates the carousel after content has been fetched.
     */
     function _update(data) {

      if (data.length === 0) {
        full = true; 
      }

      for (var i in data) {
        var $item = $(data[i]);
        $('.open-platform-item-list').append($item).packery('appended', $item);
      }

      
      console.log("update");
    }

    /**
     * Private: Check if we need to fetch more content.
     */
     function _ready_to_fetch($carousel) {

      if (running_request) {
        return false;
      }

      if (full) {
        return false;
      }

      return true;
    }




     /**
     * Private: Makes an ajax call to the server to get new content for the
     * carousel. The search context is send along with the ajax request.
     */
     function _fetch(offset) {
      console.log("fetch");

      $('#ajax-loader').show();

      // Register that an asyncrounous ajax call is started
      running_request = true;

      $.ajax({
       type: 'post',
       url : Drupal.settings.basePath + 'bibsdb_open_platform_query/content/ajax',
       dataType : 'json',
       data: {
        'nid' : $('.open-platform-item-list').attr('id'),
        'offset' : offset
      },
      success : function(data) {
          // Update the carousel.
          console.log(data);
          $('#ajax-loader').hide();
          _update(data);
        },
        complete : function() {
          // Register that an asyncrounous ajax call has ended
          running_request = false; 

          // Remove spinner
          //$(".newmaterials .query").css('background-image', 'none');
          
          // Fetch again if there are few slides in the carousel
          //if (_ready_to_fetch($carousel)) {
            //_fetch($carousel, $carousel.slick('getSlick').slideCount);
          //}
        }
      });
    }


    /**
     * Public: Init the item list.
     */
     function init() {
      console.log("init");
      var $boxes = $('.open-platform-item');
      $boxes.hide();

      var $container = $('.open-platform-item-list');
      $container.imagesLoaded( function() {
        $boxes.fadeIn();

        $container.packery({
          itemSelector: '.open-platform-item',
        });    
      });

      // Fetch the first 15 items
      _fetch(0);

      // Tie event handler to load-button
      $( "#load-button" ).click(function() {
        _load_more();
      });


    }

    /**
     * Expoes public functions.
     */
     return {
      name: 'bibsdb_open_platform_list',
      init: init,
    };
  })();

  /**
   * Start the carousel when the document is ready.
   */
   $(document).ready(function() {
    BibsdbOpenPlatformList.init();
  });


 })(jQuery);