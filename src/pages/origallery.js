import React from "react"
import { graphql } from "gatsby"
const Layout =
  require('../components/layout/Layout.bs.js').make;
const PhotoGrid =
  require('../components/layout/gallery/PhotoGrid.bs.js').make;


export default ({ data }) => {
  return (
    < Layout >
      <PhotoGrid photos={data.allFile.edges} />
    </Layout >
  )
}

export const query = graphql`
query MyQuery {
    allFile(filter: {sourceInstanceName: {eq: "origami"}}) {
      edges {
        node {
          childImageSharp {
            fluid(maxWidth: 1900, fit: COVER){
              ...GatsbyImageSharpFluid_withWebp_tracedSVG
              originalImg
              originalName
            }
            fixed(width: 200, height: 200){
              ...GatsbyImageSharpFixed_withWebp_tracedSVG
            }
          }
        }
      }
    }
  }
`;