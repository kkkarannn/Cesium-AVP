// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!

#include "registerWriterExtensions.h"

#include "ModelJsonWriter.h"

#include <CesiumGltf/Buffer.h>
#include <CesiumGltf/BufferView.h>
#include <CesiumGltf/ExtensionBufferExtMeshoptCompression.h>
#include <CesiumGltf/ExtensionBufferViewExtMeshoptCompression.h>
#include <CesiumGltf/ExtensionCesiumPrimitiveOutline.h>
#include <CesiumGltf/ExtensionCesiumRTC.h>
#include <CesiumGltf/ExtensionCesiumTileEdges.h>
#include <CesiumGltf/ExtensionExtInstanceFeatures.h>
#include <CesiumGltf/ExtensionExtMeshFeatures.h>
#include <CesiumGltf/ExtensionExtMeshGpuInstancing.h>
#include <CesiumGltf/ExtensionKhrDracoMeshCompression.h>
#include <CesiumGltf/ExtensionKhrMaterialsUnlit.h>
#include <CesiumGltf/ExtensionKhrTextureBasisu.h>
#include <CesiumGltf/ExtensionKhrTextureTransform.h>
#include <CesiumGltf/ExtensionMeshPrimitiveExtStructuralMetadata.h>
#include <CesiumGltf/ExtensionMeshPrimitiveKhrMaterialsVariants.h>
#include <CesiumGltf/ExtensionModelExtStructuralMetadata.h>
#include <CesiumGltf/ExtensionModelKhrMaterialsVariants.h>
#include <CesiumGltf/ExtensionModelMaxarMeshVariants.h>
#include <CesiumGltf/ExtensionNodeMaxarMeshVariants.h>
#include <CesiumGltf/ExtensionTextureWebp.h>
#include <CesiumGltf/FeatureIdTexture.h>
#include <CesiumGltf/Material.h>
#include <CesiumGltf/MaterialNormalTextureInfo.h>
#include <CesiumGltf/MaterialOcclusionTextureInfo.h>
#include <CesiumGltf/MeshPrimitive.h>
#include <CesiumGltf/Model.h>
#include <CesiumGltf/Node.h>
#include <CesiumGltf/PropertyTextureProperty.h>
#include <CesiumGltf/Texture.h>
#include <CesiumGltf/TextureInfo.h>
#include <CesiumJsonWriter/ExtensionWriterContext.h>

namespace CesiumGltfWriter {

void registerWriterExtensions(
    CesiumJsonWriter::ExtensionWriterContext& context) {
  (void)context;
  context.registerExtension<CesiumGltf::Model, ExtensionCesiumRTCJsonWriter>();
  context.registerExtension<
      CesiumGltf::Model,
      ExtensionModelExtStructuralMetadataJsonWriter>();
  context.registerExtension<
      CesiumGltf::Model,
      ExtensionModelKhrMaterialsVariantsJsonWriter>();
  context.registerExtension<
      CesiumGltf::Model,
      ExtensionModelMaxarMeshVariantsJsonWriter>();
  context.registerExtension<
      CesiumGltf::MeshPrimitive,
      ExtensionCesiumTileEdgesJsonWriter>();
  context.registerExtension<
      CesiumGltf::MeshPrimitive,
      ExtensionExtMeshFeaturesJsonWriter>();
  context.registerExtension<
      CesiumGltf::MeshPrimitive,
      ExtensionMeshPrimitiveExtStructuralMetadataJsonWriter>();
  context.registerExtension<
      CesiumGltf::MeshPrimitive,
      ExtensionKhrDracoMeshCompressionJsonWriter>();
  context.registerExtension<
      CesiumGltf::MeshPrimitive,
      ExtensionMeshPrimitiveKhrMaterialsVariantsJsonWriter>();
  context.registerExtension<
      CesiumGltf::MeshPrimitive,
      ExtensionCesiumPrimitiveOutlineJsonWriter>();
  context.registerExtension<
      CesiumGltf::Node,
      ExtensionExtInstanceFeaturesJsonWriter>();
  context.registerExtension<
      CesiumGltf::Node,
      ExtensionExtMeshGpuInstancingJsonWriter>();
  context.registerExtension<
      CesiumGltf::Node,
      ExtensionNodeMaxarMeshVariantsJsonWriter>();
  context.registerExtension<
      CesiumGltf::Buffer,
      ExtensionBufferExtMeshoptCompressionJsonWriter>();
  context.registerExtension<
      CesiumGltf::BufferView,
      ExtensionBufferViewExtMeshoptCompressionJsonWriter>();
  context.registerExtension<
      CesiumGltf::Material,
      ExtensionKhrMaterialsUnlitJsonWriter>();
  context.registerExtension<
      CesiumGltf::Texture,
      ExtensionKhrTextureBasisuJsonWriter>();
  context
      .registerExtension<CesiumGltf::Texture, ExtensionTextureWebpJsonWriter>();
  context.registerExtension<
      CesiumGltf::TextureInfo,
      ExtensionKhrTextureTransformJsonWriter>();
  context.registerExtension<
      CesiumGltf::MaterialOcclusionTextureInfo,
      ExtensionKhrTextureTransformJsonWriter>();
  context.registerExtension<
      CesiumGltf::MaterialNormalTextureInfo,
      ExtensionKhrTextureTransformJsonWriter>();
  context.registerExtension<
      CesiumGltf::PropertyTextureProperty,
      ExtensionKhrTextureTransformJsonWriter>();
  context.registerExtension<
      CesiumGltf::FeatureIdTexture,
      ExtensionKhrTextureTransformJsonWriter>();
}
} // namespace CesiumGltfWriter
