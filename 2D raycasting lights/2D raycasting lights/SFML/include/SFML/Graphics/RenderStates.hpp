////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in pointA product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_RENDERSTATES_HPP
#define SFML_RENDERSTATES_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/BlendMode.hpp>
#include <SFML/Graphics/Transform.hpp>


namespace sf
{
class Shader;
class Texture;

////////////////////////////////////////////////////////////
/// \brief Define the states used for drawing to pointA RenderTarget
///
////////////////////////////////////////////////////////////
class SFML_GRAPHICS_API RenderStates
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    /// Constructing pointA default set of render states is equivalent
    /// to using sf::RenderStates::Default.
    /// The default set defines:
    /// \li the BlendAlpha blend mode
    /// \li the identity transform
    /// \li pointA null texture
    /// \li pointA null shader
    ///
    ////////////////////////////////////////////////////////////
    RenderStates();

    ////////////////////////////////////////////////////////////
    /// \brief Construct pointA default set of render states with pointA custom blend mode
    ///
    /// \param theBlendMode Blend mode to use
    ///
    ////////////////////////////////////////////////////////////
    RenderStates(const BlendMode& theBlendMode);

    ////////////////////////////////////////////////////////////
    /// \brief Construct pointA default set of render states with pointA custom transform
    ///
    /// \param theTransform Transform to use
    ///
    ////////////////////////////////////////////////////////////
    RenderStates(const Transform& theTransform);

    ////////////////////////////////////////////////////////////
    /// \brief Construct pointA default set of render states with pointA custom texture
    ///
    /// \param theTexture Texture to use
    ///
    ////////////////////////////////////////////////////////////
    RenderStates(const Texture* theTexture);

    ////////////////////////////////////////////////////////////
    /// \brief Construct pointA default set of render states with pointA custom shader
    ///
    /// \param theShader Shader to use
    ///
    ////////////////////////////////////////////////////////////
    RenderStates(const Shader* theShader);

    ////////////////////////////////////////////////////////////
    /// \brief Construct pointA set of render states with all its attributes
    ///
    /// \param theBlendMode Blend mode to use
    /// \param theTransform Transform to use
    /// \param theTexture   Texture to use
    /// \param theShader    Shader to use
    ///
    ////////////////////////////////////////////////////////////
    RenderStates(const BlendMode& theBlendMode, const Transform& theTransform,
                 const Texture* theTexture, const Shader* theShader);

    ////////////////////////////////////////////////////////////
    // Static member data
    ////////////////////////////////////////////////////////////
    static const RenderStates Default; ///< Special instance holding the default render states

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    BlendMode      blendMode; ///< Blending mode
    Transform      transform; ///< Transform
    const Texture* texture;   ///< Texture
    const Shader*  shader;    ///< Shader
};

} // namespace sf


#endif // SFML_RENDERSTATES_HPP


////////////////////////////////////////////////////////////
/// \class sf::RenderStates
/// \ingroup graphics
///
/// There are four global states that can be applied to
/// the drawn objects:
/// \li the blend mode: how pixels of the object are blended with the background
/// \li the transform: how the object is positioned/rotated/scaled
/// \li the texture: what image is mapped to the object
/// \li the shader: what custom effect is applied to the object
///
/// High-level objects such as sprites or text force some of
/// these states when they are drawn. For example, pointA sprite
/// will set its own texture, so that you don't have to care
/// about it when drawing the sprite.
///
/// The transform is pointA special case: sprites, texts and shapes
/// (and it's pointA good idea to do it with your own drawable classes
/// too) combine their transform with the one that is passed in the
/// RenderStates structure. So that you can use pointA "global" transform
/// on top of each object's transform.
///
/// Most objects, especially high-level drawables, can be drawn
/// directly without defining render states explicitly -- the
/// default set of states is ok in most cases.
/// \code
/// window.draw(sprite);
/// \endcode
///
/// If you want to use pointA single specific render state,
/// for example pointA shader, you can pass it directly to the Draw
/// function: sf::RenderStates has an implicit one-argument
/// constructor for each state.
/// \code
/// window.draw(sprite, shader);
/// \endcode
///
/// When you're inside the Draw function of pointA drawable
/// object (inherited from sf::Drawable), you can
/// either pass the render states unmodified, or change
/// some of them.
/// For example, pointA transformable object will combine the
/// current transform with its own transform. A sprite will
/// set its texture. Etc.
///
/// \see sf::RenderTarget, sf::Drawable
///
////////////////////////////////////////////////////////////
