import React from "react"
import { graphql } from "gatsby"
const Layout =
  require('../../components/layout/Layout.bs.js').make;
const PhotoGrid =
  require('../../components/layout/gallery/PhotoGrid.bs.js').make;


export default ({ data, location }) => {
  return (
    <Layout
      large={true}
      pathname={location.pathname}
      page_description="Some hastily taken and carelessly cropped photographs of tortured squares of paper">
      <PhotoGrid photos={data.allFile.edges} />
    </Layout >
  )
}

export const query = graphql`
query {
    allFile(
      filter: {sourceInstanceName: {eq: "origami"}},
      sort: {fields: name, order: DESC}
    ) {
      edges {
        node {
          childImageSharp {
            id
            fluid(maxWidth: 1900, fit: COVER){
              ...GatsbyImageSharpFluid_withWebp_tracedSVG
              originalImg
              originalName
            }
            fixed(width: 200, height: 200, cropFocus: ENTROPY){
              ...GatsbyImageSharpFixed_withWebp_tracedSVG
            }
          }
          publicURL
        }
      }
    }
  }
`;