<?php
/**
 * @file
 * photo_album_content_type.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function photo_album_content_type_image_default_styles() {
  $styles = array();

  // Exported image style: photo-album.
  $styles['photo-album'] = array(
    'name' => 'photo-album',
    'effects' => array(
      12 => array(
        'label' => 'Subroutine',
        'help' => 'Runs another defined preset on the image.',
        'effect callback' => 'imagecache_subroutine_image',
        'dimensions callback' => 'imagecache_subroutine_dimensions',
        'form callback' => 'imagecache_subroutine_form',
        'module' => 'imagecache_customactions',
        'name' => 'imagecache_subroutine',
        'data' => array(
          'subroutine_presetname' => 'stamp',
        ),
        'weight' => '1',
      ),
      13 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '700',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: photos-slideshow.
  $styles['photos-slideshow'] = array(
    'name' => 'photos-slideshow',
    'effects' => array(
      14 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '1024',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
      15 => array(
        'label' => 'Subroutine',
        'help' => 'Runs another defined preset on the image.',
        'effect callback' => 'imagecache_subroutine_image',
        'dimensions callback' => 'imagecache_subroutine_dimensions',
        'form callback' => 'imagecache_subroutine_form',
        'module' => 'imagecache_customactions',
        'name' => 'imagecache_subroutine',
        'data' => array(
          'subroutine_presetname' => 'stamp',
        ),
        'weight' => '2',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function photo_album_content_type_node_info() {
  $items = array(
    'photo_album' => array(
      'name' => t('Photo Album'),
      'base' => 'node_content',
      'description' => t('Photos of Images'),
      'has_title' => '1',
      'title_label' => t('Album Name'),
      'help' => t('The Album name will be used on the gallery page to direct users to these images.'),
    ),
  );
  return $items;
}
